// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSovereignPhoenixStateVectorCompiler.h"

UAshenSovereignPhoenixStateVectorCompiler::UAshenSovereignPhoenixStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSovereignPhoenixStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSovereignPhoenixStateVectorCompiler::CompileSovereignPhoenixStateVector(float SovereignValue)
{
	CompiledSovereignPhoenixScalar = FMath::Clamp(SovereignValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSovereignPhoenixStateVectorCompiler: Compiled sovereign phoenix state vector scalar to %f"), CompiledSovereignPhoenixScalar);
}
