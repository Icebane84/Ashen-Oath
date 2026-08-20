// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenInnerWorldStateVectorCompiler.h"

UAshenInnerWorldStateVectorCompiler::UAshenInnerWorldStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenInnerWorldStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenInnerWorldStateVectorCompiler::CompileInnerWorldStateVector(float MemoryIntegrity)
{
	CompiledInnerWorldIntegrityScalar = FMath::Clamp(MemoryIntegrity, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenInnerWorldStateVectorCompiler: Compiled Inner World memory integrity scalar to %f"), CompiledInnerWorldIntegrityScalar);
}
