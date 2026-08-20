// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenCrisisStateVectorCompiler.h"

UAshenCrisisStateVectorCompiler::UAshenCrisisStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCrisisStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCrisisStateVectorCompiler::CompileCrisisStateVector(float CrisisValue)
{
	CompiledCrisisStateScalar = FMath::Clamp(CrisisValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenCrisisStateVectorCompiler: Compiled crisis state vector scalar to %f"), CompiledCrisisStateScalar);
}
