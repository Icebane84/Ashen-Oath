// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenVeilPhaseStateVectorCompiler.h"

UAshenVeilPhaseStateVectorCompiler::UAshenVeilPhaseStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenVeilPhaseStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenVeilPhaseStateVectorCompiler::CompileVeilPhaseStateVector(float ShiftIntensity)
{
	CompiledPhaseDissonanceScalar = FMath::Clamp(ShiftIntensity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenVeilPhaseStateVectorCompiler: Compiled veil phase state vector scalar to %f"), CompiledPhaseDissonanceScalar);
}
