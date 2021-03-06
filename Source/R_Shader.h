#ifndef __ResourceShader_H__
#define __ResourceShader_H__

#include "Dependencies/glew/include/glew.h"

#include "Resource.h"
#include "Dependencies/MathGeoLib/include/Math/float2.h"
#include "Dependencies/MathGeoLib/include/Math/float3.h"
#include "Dependencies/MathGeoLib/include/Math/float4.h"
#include "Dependencies/MathGeoLib/include/Math/float4x4.h"

enum class UniformType
{
	INT,
	FLOAT,
	BOOL,
	INT_VEC2,
	INT_VEC3,
	INT_VEC4,
	FLOAT_VEC2,
	FLOAT_VEC3,
	FLOAT_VEC4,
	MATRIX4,
	NONE
};

struct Uniform
{
	UniformType uniformType = UniformType::NONE;
	std::string name;
	GLenum		GLtype;

	bool		boolean;
	GLint		integer;
	GLfloat		floatNumber;
	float2		vec2;
	float3		vec3;
	float4		vec4;
	float4x4	matrix4 = float4x4::zero;

};

class MISSCLICK_API R_Shader : public Resource
{
public:
	R_Shader();
	~R_Shader();

	bool SaveMeta(ParsonNode& metaRoot) const override;
	bool LoadMeta(const ParsonNode& metaRoot) override;

	static inline ResourceType GetType() { return ResourceType::SHADER; }

public:
	void		SetUniformMatrix4(std::string name, GLfloat* value, int size = 1);

	void		SetUniformVec2f(std::string name, GLfloat* value);
	void		SetUniformVec3f(std::string name, GLfloat* value);
	void		SetUniformVec4f(std::string name, GLfloat* value);

	void		SetUniformVec2i(std::string name, GLint* value);
	void		SetUniformVec3i(std::string name, GLint* value);
	void		SetUniformVec4i(std::string name, GLint* value);

	void		SetUniform1f(std::string name, GLfloat value);
	void		SetUniform1i(std::string name, GLint value);

public:
	uint32		shaderProgramID = 0;
	uint32		vertexID = 0;
	uint32		fragmentID = 0;

	std::vector<Uniform> uniforms;
};
#endif //__ResourceShader_H__
