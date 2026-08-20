// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenRealityFractureTrapActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_SanityComponent.h"
#include "AshenVFXPoolSubsystem.h"
#include "GameFramework/Pawn.h"

AAshenRealityFractureTrapActor::AAshenRealityFractureTrapActor()
{
	PrimaryActorTick.bCanEverTick = false;

	TrapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TrapMesh"));
	RootComponent = TrapMesh;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerVolume"));
	TriggerVolume->SetupAttachment(RootComponent);
	TriggerVolume->SetBoxExtent(FVector(150.0f, 150.0f, 100.0f));
	TriggerVolume->SetCollisionProfileName(TEXT("Trigger"));

	VoidDamage = 50.0f;
	IsolationToll = 0.15f;
}

void AAshenRealityFractureTrapActor::BeginPlay()
{
	Super::BeginPlay();
	if (TriggerVolume)
	{
		TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &AAshenRealityFractureTrapActor::OnOverlapBegin);
	}
}

void AAshenRealityFractureTrapActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || !OtherActor->IsA<APawn>()) return;

	if (UAshenOath_HealthComponent* Health = OtherActor->FindComponentByClass<UAshenOath_HealthComponent>())
	{
		Health->ReceiveDamage(VoidDamage, this);
	}

	if (UAshenOath_SanityComponent* Sanity = OtherActor->FindComponentByClass<UAshenOath_SanityComponent>())
	{
		Sanity->SufferMentalDamage(IsolationToll * 100.0f); // Drain sanity
	}

	if (GetWorld())
	{
		if (UAshenVFXPoolSubsystem* VFXPool = GetWorld()->GetSubsystem<UAshenVFXPoolSubsystem>())
		{
			VFXPool->SpawnPooledVFX(FName("VFX_RealityFractureExplosion"), GetActorLocation(), FRotator::ZeroRotator);
		}
	}

	OnFractureTriggered.Broadcast(this, OtherActor, VoidDamage);
	UE_LOG(LogTemp, Warning, TEXT("AAshenRealityFractureTrapActor: Mindscape Reality Fracture triggered on '%s'!"), *OtherActor->GetName());

	Destroy();
}
