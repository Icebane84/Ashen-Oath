// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenGarrettCompanionCharacter.h"
#include "Combat/AshenBurningSteelOilComponent.h"
#include "Combat/AshenGhostbloomFlareComponent.h"
#include "Combat/AshenAlchemicalCaltropGridComponent.h"
#include "AI/AshenAlchemicalTrapAIDirectorComponent.h"
#include "Combat/AshenIgnitedCutlassMeshAdapter.h"
#include "Companions/AshenCompanionFormationComponent.h"
#include "Companions/AshenCompanionTrustAccumulationComponent.h"

AAshenGarrettCompanionCharacter::AAshenGarrettCompanionCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	BurningSteelOilComponent = CreateDefaultSubobject<UAshenBurningSteelOilComponent>(TEXT("BurningSteelOilComponent"));
	GhostbloomFlareComponent = CreateDefaultSubobject<UAshenGhostbloomFlareComponent>(TEXT("GhostbloomFlareComponent"));
	CaltropGridComponent = CreateDefaultSubobject<UAshenAlchemicalCaltropGridComponent>(TEXT("CaltropGridComponent"));
	TrapAIDirector = CreateDefaultSubobject<UAshenAlchemicalTrapAIDirectorComponent>(TEXT("TrapAIDirector"));
	IgnitedCutlassAdapter = CreateDefaultSubobject<UAshenIgnitedCutlassMeshAdapter>(TEXT("IgnitedCutlassAdapter"));
	FormationComponent = CreateDefaultSubobject<UAshenCompanionFormationComponent>(TEXT("FormationComponent"));
	TrustComponent = CreateDefaultSubobject<UAshenCompanionTrustAccumulationComponent>(TEXT("TrustComponent"));
}

void AAshenGarrettCompanionCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenGarrettCompanionCharacter: Garrett Companion Initialized with Alchemical Formulations & Trap Director."));
}

void AAshenGarrettCompanionCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
