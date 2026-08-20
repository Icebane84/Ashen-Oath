// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 511: Ashen Serafina Identity Compiler Subsystem

#include "AshenSerafinaIdentityCompilerSubsystem.h"

void UAshenSerafinaIdentityCompilerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveInterpretiveLens = FName(TEXT("Lens.Grace"));
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaIdentityCompilerSubsystem: Initialized — Serafina Identity Compiler Subsystem ONLINE."));
}

bool UAshenSerafinaIdentityCompilerSubsystem::CompileIdentityForCampfireLens(FName InterpretiveLensTag)
{
	if (InterpretiveLensTag.IsNone()) return false;

	ActiveInterpretiveLens = InterpretiveLensTag;
	const float Metric = (InterpretiveLensTag == FName(TEXT("Lens.Grace"))) ? 1.0f : (InterpretiveLensTag == FName(TEXT("Lens.Accountability")) ? 0.8f : 0.6f);

	OnIdentityCompiled.Broadcast(ActiveInterpretiveLens, Metric);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaIdentityCompilerSubsystem: SERAFINA CAMPFIRE RITUAL -> Identity Compiled through '%s' (Compiled Metric: %.2f) — FSoulStateVector Updated!"),
		*ActiveInterpretiveLens.ToString(), Metric);

	return true;
}
