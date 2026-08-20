// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenMindscapeTouchstoneActor.h"

AAshenMindscapeTouchstoneActor::AAshenMindscapeTouchstoneActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenMindscapeTouchstoneActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenMindscapeTouchstoneActor: Mindscape Touchstone Actor initialized."));
}

bool AAshenMindscapeTouchstoneActor::InitiateTouchstoneIntrospection(AActor* InstigatorCharacter)
{
	if (!InstigatorCharacter || !bTouchstoneActive) return false;
	UE_LOG(LogTemp, Log, TEXT("AAshenMindscapeTouchstoneActor: Initiated touchstone introspection sequence for %s"), *InstigatorCharacter->GetName());
	return true;
}
