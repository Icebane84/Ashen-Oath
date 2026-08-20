// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenUmbralSymbioteBossActor.h"

AAshenUmbralSymbioteBossActor::AAshenUmbralSymbioteBossActor()
{
	PrimaryActorTick.bCanEverTick = false;
	CurrentBossPhase = EBossPuzzlePhase::Phase1_ObservationStalemate;
}
void AAshenUmbralSymbioteBossActor::BeginPlay() { Super::BeginPlay(); }

void AAshenUmbralSymbioteBossActor::AdvanceBossPhase(EBossPuzzlePhase NextPhase)
{
	CurrentBossPhase = NextPhase;
	UE_LOG(LogTemp, Warning, TEXT("AAshenUmbralSymbioteBossActor: Advanced Boss Phase to -> %d"), static_cast<int32>(CurrentBossPhase));
}
