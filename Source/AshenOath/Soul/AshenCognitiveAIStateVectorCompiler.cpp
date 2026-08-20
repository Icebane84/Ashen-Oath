// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenCognitiveAIStateVectorCompiler.h"

UAshenCognitiveAIStateVectorCompiler::UAshenCognitiveAIStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCognitiveAIStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCognitiveAIStateVectorCompiler::CompileCognitiveStateVector(float ThreatValue)
{
	CompiledAIThreatScalar = FMath::Clamp(ThreatValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenCognitiveAIStateVectorCompiler: Compiled cognitive AI state vector scalar to %f"), CompiledAIThreatScalar);
}
