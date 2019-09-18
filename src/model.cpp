#include "model.h"

Model::Model() : gammaCorrection(true) { return; }

void Model::Draw(Shader shader)
{
    for(unsigned int i = 0; i < this->meshes.size(); i++)
    {
        this->meshes[i].Draw(shader);
    }
}

void Model::loadModel(string const &path)
{
    Assimp::Importer importer;
    const aiScene* scene;
    
    scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        errorMessage("assimp " + string(importer.GetErrorString()));
        return;
    }
    this->directory = path.substr(0, path.find_last_of('/'));
    processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
    for(int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        this->meshes.push_back(processMesh(mesh, scene));
    }
    for(int i = 0; i < node->mNumChildren; i++)
    {
		if (node->mChildren[i])
		{
			processNode(node->mChildren[i], scene);
		}
    }
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
    vector<Vertex> vertices;
    vector<unsigned int> triangles;
    vector<Texture> textures;
	vector<Bone> bones;
    
    vertices = Model::loadVertices(mesh);
    triangles = Model::loadTriangles(mesh);
    textures = Model::loadTextures(mesh, scene);
    bones = Model::loadBones(mesh);
    return Mesh(vertices, triangles, textures, bones);
}

vector<Vertex> Model::loadVertices(aiMesh *mesh)
{
    vector<Vertex> vertices;
    
    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        glm::vec3 vector;
        
        vector.x = mesh->mVertices[i].x;
        vector.y = mesh->mVertices[i].y;
        vector.z = mesh->mVertices[i].z;
        vertex.position = vector;

        vector.x = mesh->mNormals[i].x;
        vector.y = mesh->mNormals[i].y;
        vector.z = mesh->mNormals[i].z;
        vertex.normal = vector;

        if(mesh->mTextureCoords[0])
        {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x; 
            vec.y = mesh->mTextureCoords[0][i].y;
            vertex.texCoords = vec;
        }
        else
        {
            vertex.texCoords = glm::vec2(0.0f, 0.0f);
        }
        
		if (mesh->mTangents != nullptr)
		{
			vector.x = mesh->mTangents[i].x;
			vector.y = mesh->mTangents[i].y;
			vector.z = mesh->mTangents[i].z;
			vertex.tangent = vector;
		}
		if (mesh->mBitangents != nullptr)
		{
			vector.x = mesh->mBitangents[i].x;
			vector.y = mesh->mBitangents[i].y;
			vector.z = mesh->mBitangents[i].z;
			vertex.bitangent = vector;
		}
        vertices.push_back(vertex);
    }
    return (vertices);
}

vector<unsigned int> Model::loadTriangles(aiMesh *mesh)
{
    vector<unsigned int> triangles;
    
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++)
            triangles.push_back(face.mIndices[j]);
    }
    return (triangles);
}

vector<Texture> Model::loadTextures(aiMesh *mesh, const aiScene *scene)
{
    vector<Texture> textures;
    aiMaterial* material;
    
    material = scene->mMaterials[mesh->mMaterialIndex];
    vector<Texture> diffuseMaps = Model::loadMaterialTextures(material, aiTextureType_DIFFUSE, DIFFUSE_TEXTURE);
    textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
    vector<Texture> specularMaps = Model::loadMaterialTextures(material, aiTextureType_SPECULAR, SPECULAR_TEXTURE);
    textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
    std::vector<Texture> normalMaps = Model::loadMaterialTextures(material, aiTextureType_HEIGHT, NORMAL_TEXTURE);
    textures.insert(textures.end(), normalMaps.begin(), normalMaps.end());
    std::vector<Texture> heightMaps = Model::loadMaterialTextures(material, aiTextureType_AMBIENT, HEIGHT_TEXTURE);
    textures.insert(textures.end(), heightMaps.begin(), heightMaps.end());
    return (textures);
}

vector<Texture> Model::loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName)
{
    vector<Texture> textures;

    for(unsigned int i = 0; i < mat->GetTextureCount(type); i++)
    {
        aiString path;
        mat->GetTexture(type, i, &path);
        textures.push_back(Texture::load(this->directory + "/" + string(path.C_Str()), typeName));
    }
    return (textures);
}

vector<Bone> Model::loadBones(aiMesh *mesh)
{
    vector<Bone> bones;

    for (unsigned int i = 0; i < mesh->mNumBones; i++)
    {
        Bone bone;

        aiMatrix4x4 m = mesh->mBones[i]->mOffsetMatrix;
        bone.name = string(mesh->mBones[i]->mName.C_Str());
        for (int j = 0; j < 3; j++)
        {
            if (j < mesh->mBones[i]->mNumWeights)
            {
                bone.IDs[j] = mesh->mBones[i]->mWeights[j].mVertexId;
                bone.Weights[j] = mesh->mBones[i]->mWeights[j].mWeight;
            }
            else
            {
                bone.IDs[j] = 0;
                bone.Weights[j] = 0;
            }
            
        }
        bone.offset = mat4(
            m[0][1], m[0][2], m[0][3], m[0][4],
            m[1][1], m[1][2], m[1][3], m[1][4],
            m[2][1], m[2][2], m[2][3], m[2][4],
            m[3][1], m[3][2], m[3][3], m[3][4]
            );
        bones.push_back(bone);  
    }
    return (bones);
}