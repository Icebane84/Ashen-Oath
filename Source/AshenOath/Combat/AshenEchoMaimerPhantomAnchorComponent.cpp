// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenEchoMaimerPhantomAnchorComponent.h"

UAshenEchoMaimerPhantomAnchorComponent::UAshenEchoMaimerPhantomAnchorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenEchoMaimerPhantomAnchorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenEchoMaimerPhantomAnchorComponent::SpawnPhantomHitbox(FVector Location)
{
	ActivePhantomHitboxes++;
	UE_LOG(LogTemp, Log, TEXT("UAshenEchoMaimerPhantomAnchorComponent: Spawned phantom ghost hitbox at %s (Total: %d)."),
		*Location.ToString(), ActivePhantomHitboxes);
}

void UAshenEchoMaimerPhantomAnchorComponent::CollapseAllPhantomTimelines()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenEchoMaimerPhantomAnchorComponent: CHRONOS-SHATTER ANCHOR! Collapsed %d phantom timeline hitboxes into single frame."),
		ActivePhantomHitboxes);
	ActivePhantomHitboxes = 0;
}
