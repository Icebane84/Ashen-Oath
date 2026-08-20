// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenGrandMasterStateVectorCompiler.h"

UAshenGrandMasterStateVectorCompiler::UAshenGrandMasterStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGrandMasterStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenGrandMasterStateVectorCompiler::CompileGrandMasterStateVector(float MilestoneValue)
{
	CompiledGrandMasterScalar = FMath::Clamp(MilestoneValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGrandMasterStateVectorCompiler: Compiled Grand Master state vector scalar to %f"), CompiledGrandMasterScalar);
}
