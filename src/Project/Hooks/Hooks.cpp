#include "Hooks.h"
#include "RE/Offsets.h"
//thanks to Nightfallstorm for the AE offset. I don't know if the VR offset works at all
void Loki::Hooks::InstallActorUpdateHook() {

	REL::Relocation<std::uintptr_t> ActorUpdate{ RELOCATION_ID(36357, 37348), REL::VariantOffset(0x6D3, 0x674, 0x6D3) };

	auto& trampoline = SKSE::GetTrampoline();
	_ActorUpdateF = trampoline.write_call<5>(ActorUpdate.address(), ActorUpdateF);

}
