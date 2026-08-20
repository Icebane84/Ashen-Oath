// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenDualityStateVectorCompiler.h"

UAshenDualityStateVectorCompiler::UAshenDualityStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDualityStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDualityStateVectorCompiler::CompileDualityStateVector(float DualityValue)
{
	CompiledDualityStateScalar = FMath::Clamp(DualityValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDualityStateVectorCompiler: Compiled Duality state vector scalar to %f"), CompiledDualityStateScalar);
}
