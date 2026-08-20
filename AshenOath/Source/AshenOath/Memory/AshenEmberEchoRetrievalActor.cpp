// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenEmberEchoRetrievalActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "GameFramework/Pawn.h"

AAshenEmberEchoRetrievalActor::AAshenEmberEchoRetrievalActor()
{
	PrimaryActorTick.bCanEverTick = false;

	EchoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EchoMesh"));
	RootComponent = EchoMesh;

	RetrievalVolume = CreateDefaultSubobject<USphereComponent>(TEXT("RetrievalVolume"));
	RetrievalVolume->SetupAttachment(RootComponent);
	RetrievalVolume->SetSphereRadius(150.0f);
	RetrievalVolume->SetCollisionProfileName(TEXT("Trigger"));

	StoredEmbers = 500.0f;
	StoredImprintCount = 2;
}

void AAshenEmberEchoRetrievalActor::BeginPlay()
{
	Super::BeginPlay();
	if (RetrievalVolume)
	{
		RetrievalVolume->OnComponentBeginOverlap.AddDynamic(this, &AAshenEmberEchoRetrievalActor::OnOverlapBegin);
	}
}

void AAshenEmberEchoRetrievalActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->IsA<APawn>())
	{
		RetrieveEcho(OtherActor);
	}
}

void AAshenEmberEchoRetrievalActor::RetrieveEcho(AActor* PlayerActor)
{
	if (!PlayerActor) return;

	if (UAshenOath_CurrencyComponent* Currency = PlayerActor->FindComponentByClass<UAshenOath_CurrencyComponent>())
	{
		Currency->AddEmbers(StoredEmbers);
	}

	if (UAshenOath_ImprintBufferComponent* ImprintComp = PlayerActor->FindComponentByClass<UAshenOath_ImprintBufferComponent>())
	{
		for (int32 i = 0; i < StoredImprintCount; ++i)
		{
			ImprintComp->AddImprint(EImprintType::Combat, 0.5f);
		}
	}

	OnEchoRetrieved.Broadcast(StoredEmbers, StoredImprintCount);
	UE_LOG(LogTemp, Warning, TEXT("AAshenEmberEchoRetrievalActor: Player recovered %.0f Embers and %d Imprints from Ember Echo!"), StoredEmbers, StoredImprintCount);

	Destroy();
}
