#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "vector.h"
#include "mesh.h"
#include "shader.h"
#include "icomponent.h"
#include "system.h"

class Model : public IComponent
{
	private:
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, string typeName);

    public:
		Model();

    vector<Mesh> meshes;
    string directory;
    bool gammaCorrection;

    void Draw(Shader shader);
		void loadModel(string const& path);
};

#endif
