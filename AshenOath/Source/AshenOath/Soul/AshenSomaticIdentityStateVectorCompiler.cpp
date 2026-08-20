// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSomaticIdentityStateVectorCompiler.h"

UAshenSomaticIdentityStateVectorCompiler::UAshenSomaticIdentityStateVectorCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticIdentityStateVectorCompiler::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticIdentityStateVectorCompiler::CompileSomaticIdentityStateVector(float EchoValue)
{
	CompiledIdentityEchoScalar = FMath::Clamp(EchoValue, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticIdentityStateVectorCompiler: Compiled somatic identity state vector scalar to %f"), CompiledIdentityEchoScalar);
}
