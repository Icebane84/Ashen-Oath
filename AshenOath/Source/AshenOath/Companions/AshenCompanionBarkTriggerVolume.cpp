// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenCompanionBarkTriggerVolume.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

AAshenCompanionBarkTriggerVolume::AAshenCompanionBarkTriggerVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->InitBoxExtent(FVector(250.0f, 250.0f, 150.0f));
	BoxComponent->SetCollisionProfileName(TEXT("Trigger"));
	RootComponent = BoxComponent;
}

void AAshenCompanionBarkTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AAshenCompanionBarkTriggerVolume::OnOverlapBegin);
}

void AAshenCompanionBarkTriggerVolume::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if ((bPlayOnce && bAlreadyTriggered) || !OtherActor || !OtherActor->IsA<APawn>())
	{
		return;
	}

	bAlreadyTriggered = true;

	// Find matching companion actor in world to trigger voice bark
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), Actors);
	for (AActor* Actor : Actors)
	{
		if (UAshenCompanionBarkComponent* BarkComp = Actor->FindComponentByClass<UAshenCompanionBarkComponent>())
		{
			if (BarkComp->CompanionType == TargetCompanion)
			{
				BarkComp->SpeakBarkLine(BarkLine);
				OnBarkVolumeTriggered.Broadcast(TargetCompanion, BarkLine);
				UE_LOG(LogTemp, Warning, TEXT("AAshenCompanionBarkTriggerVolume: Triggered bark for companion %d: '%s'"),
					static_cast<int32>(TargetCompanion), *BarkLine);
				break;
			}
		}
	}
}
