// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenSerafinaCompanionCharacter.h"
#include "Companions/AshenSerafinaBurnoutComponent.h"
#include "Companions/AshenSerafinaAuraFieldComponent.h"
#include "Combat/AshenLuminousAegisNetComponent.h"
#include "Combat/AshenTransferenceCatharsisComponent.h"
#include "Combat/AshenTransferenceSymptomComponent.h"
#include "Combat/AshenSerafinaStainedCuffMeshAdapter.h"
#include "AI/AshenSerafinaWeavingAIDirectorComponent.h"
#include "Companions/AshenCompanionFormationComponent.h"
#include "Companions/AshenCompanionTrustAccumulationComponent.h"

AAshenSerafinaCompanionCharacter::AAshenSerafinaCompanionCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	BurnoutComponent = CreateDefaultSubobject<UAshenSerafinaBurnoutComponent>(TEXT("BurnoutComponent"));
	AuraFieldComponent = CreateDefaultSubobject<UAshenSerafinaAuraFieldComponent>(TEXT("AuraFieldComponent"));
	AegisNetComponent = CreateDefaultSubobject<UAshenLuminousAegisNetComponent>(TEXT("AegisNetComponent"));
	CatharsisComponent = CreateDefaultSubobject<UAshenTransferenceCatharsisComponent>(TEXT("CatharsisComponent"));
	SymptomComponent = CreateDefaultSubobject<UAshenTransferenceSymptomComponent>(TEXT("SymptomComponent"));
	StainedCuffAdapter = CreateDefaultSubobject<UAshenSerafinaStainedCuffMeshAdapter>(TEXT("StainedCuffAdapter"));
	WeavingAIDirector = CreateDefaultSubobject<UAshenSerafinaWeavingAIDirectorComponent>(TEXT("WeavingAIDirector"));
	FormationComponent = CreateDefaultSubobject<UAshenCompanionFormationComponent>(TEXT("FormationComponent"));
	TrustComponent = CreateDefaultSubobject<UAshenCompanionTrustAccumulationComponent>(TEXT("TrustComponent"));
}

void AAshenSerafinaCompanionCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenSerafinaCompanionCharacter: Serafina Companion Initialized with Weaving Loom & Empathic Components."));
}

void AAshenSerafinaCompanionCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
