// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Soul/AshenMindscapeIdentityCompilerComponent.h"

UAshenMindscapeIdentityCompilerComponent::UAshenMindscapeIdentityCompilerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenMindscapeIdentityCompilerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenMindscapeIdentityCompilerComponent::CompileIdentityFragment(FName FragmentID)
{
	CompiledIdentityFragments++;
	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeIdentityCompilerComponent: Compiled identity fragment %s. Total fragments: %d"), *FragmentID.ToString(), CompiledIdentityFragments);
}
