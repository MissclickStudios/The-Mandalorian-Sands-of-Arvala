#ifndef __EMITTER_INSTANCE_H__
#define __EMITTER_INSTANCE_H__

#include "Globals.h"
#include "Particle.h"

#include <map>
#include <vector>

class R_Texture;
class C_ParticleSystem;
class Emitter;

class EmitterInstance
{
public:
	EmitterInstance();
	EmitterInstance(Emitter* emitter, C_ParticleSystem* component);
	~EmitterInstance();

	//if emitter equals null, a default emitter is added
	void Init(Emitter* emitter, C_ParticleSystem* component);		
	void Update(float dt);
	void DrawParticles();

	void SpawnParticle();
	void ResetEmitter();

public:

	void UpdateModules(float dt);
	void KillDeadParticles();
	void KillAll();

	void GetActiveParticles(std::map<float, Particle*>& _activeParticles);
	R_Texture* GetEmitterTexture();

public:
	unsigned int activeParticles = 0;
	std::vector<Particle> particles;
	unsigned int* particleIndices = nullptr;
	
	float emitterTime = 0.0f;

	Emitter* emitter = nullptr;
	C_ParticleSystem* component = nullptr;

	bool stopSpawn = false;
};

#endif //!__EMITTER_INSTANCE_H__