// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenVeilPhaseFilterStateVectorCompiler.h"

UAshenVeilPhaseFilterStateVectorCompiler::UAshenVeilPhaseFilterStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenVeilPhaseFilterStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenVeilPhaseFilterStateVectorCompiler::CompileVeilPhaseFilterStateVector(float FilterValue)
{
	CompiledVeilPhaseFilterScalar = FMath::Clamp(FilterValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenVeilPhaseFilterStateVectorCompiler: Compiled veil phase filter state vector scalar to %f"), CompiledVeilPhaseFilterScalar);
}
