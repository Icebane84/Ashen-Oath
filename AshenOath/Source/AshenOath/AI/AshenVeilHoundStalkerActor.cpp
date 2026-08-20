// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenVeilHoundStalkerActor.h"

AAshenVeilHoundStalkerActor::AAshenVeilHoundStalkerActor()
{
	PrimaryActorTick.bCanEverTick = false;
	StalkingSpeed = 550.0f;
}
void AAshenVeilHoundStalkerActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenVeilHoundStalkerActor::AttemptFlankAmbush(AActor* TargetHero, bool bHeroIsHunched)
{
	if (!TargetHero) return false;
	if (bHeroIsHunched)
	{
		UE_LOG(LogTemp, Warning, TEXT("AAshenVeilHoundStalkerActor: FLANK AMBUSH SUCCESSFUL! Exploited hunched blindspot on %s!"), *TargetHero->GetName());
		return true;
	}
	UE_LOG(LogTemp, Log, TEXT("AAshenVeilHoundStalkerActor: Flank ambush detected and parried by %s."), *TargetHero->GetName());
	return false;
}
