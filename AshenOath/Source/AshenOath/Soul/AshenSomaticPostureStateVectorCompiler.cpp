// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSomaticPostureStateVectorCompiler.h"

UAshenSomaticPostureStateVectorCompiler::UAshenSomaticPostureStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticPostureStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticPostureStateVectorCompiler::CompileSomaticPostureStateVector(float AlignmentValue)
{
	CompiledPostureAlignmentScalar = FMath::Clamp(AlignmentValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPostureStateVectorCompiler: Compiled somatic posture state vector scalar to %f"), CompiledPostureAlignmentScalar);
}
