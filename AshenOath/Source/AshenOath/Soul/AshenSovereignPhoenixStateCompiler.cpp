// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenSovereignPhoenixStateCompiler.h"

UAshenSovereignPhoenixStateCompiler::UAshenSovereignPhoenixStateCompiler()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSovereignPhoenixStateCompiler::BeginPlay()
{
	Super::BeginPlay();
	CompileSovereignStateVector();
}

void UAshenSovereignPhoenixStateCompiler::CompileSovereignStateVector()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenSovereignPhoenixStateCompiler: Compiled Grand Master Sovereign Phoenix State Vector (Progress: %f)."), SovereignAscensionProgress);
}
