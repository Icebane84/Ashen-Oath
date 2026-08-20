// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenMindscapeCollapseVolume.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"

AAshenMindscapeCollapseVolume::AAshenMindscapeCollapseVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(300.0f, 300.0f, 200.0f));
	BoxComponent->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = BoxComponent;
}

void AAshenMindscapeCollapseVolume::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AAshenMindscapeCollapseVolume::OnOverlapBegin);
}

void AAshenMindscapeCollapseVolume::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (bTriggered || !OtherActor || !OtherActor->IsA<APawn>())
	{
		return;
	}

	if (UAshenOath_ImprintBufferComponent* Buffer = OtherActor->FindComponentByClass<UAshenOath_ImprintBufferComponent>())
	{
		float Debt = Buffer->GetIntegrationDebt();
		EIntegrationDebtStage Stage = Buffer->GetDebtStage();

		if (Stage == EIntegrationDebtStage::ForcedCollapse || Debt >= 1.0f)
		{
			bTriggered = true;
			OnMindscapeCollapseTriggered.Broadcast(OtherActor, Debt);
			UE_LOG(LogTemp, Error, TEXT("AAshenMindscapeCollapseVolume: INVOLUNTARY MINDSCAPE COLLAPSE! Debt: %.2f (Stage 4)"), Debt);
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("AAshenMindscapeCollapseVolume: Player entered volume with safe debt level %.2f (Stage %d)"),
				Debt, static_cast<int32>(Stage));
		}
	}
}
