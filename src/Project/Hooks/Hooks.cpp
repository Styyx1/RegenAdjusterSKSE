#include "Hooks.h"
#include "RE/Offsets.h"

void Loki::Hooks::InstallActorUpdateHook() {

	REL::Relocation<std::uintptr_t> ActorUpdate{ RELOCATION_ID(36357, 37348), REL::VariantOffset(0x6D3, 0x674, 0x6D3) }; //Credits for the AE Offset goes to Nightfallstorm. I don't know if the VR offset will work.

	auto& trampoline = SKSE::GetTrampoline();
	_ActorUpdateF = trampoline.write_call<5>(ActorUpdate.address(), ActorUpdateF);

}
