#include "CombatEnemy.h"
#include "AshenOath_HealthComponent.h"
#include "Components/CapsuleComponent.h"
#include "AshenCharacterInterface.h"

ACombatEnemy::ACombatEnemy()
{
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UAshenOath_HealthComponent>(TEXT("CombatEnemyHealthComponent"));
	HealthComponent->SetMaxHealth(150.0f);
}

void ACombatEnemy::BeginPlay()
{
	Super::BeginPlay();

	if (HealthComponent)
	{
		HealthComponent->OnDied.AddDynamic(this, &ACombatEnemy::HandleDeath);
	}

	if (UCapsuleComponent* Capsule = GetCapsuleComponent())
	{
		Capsule->SetGenerateOverlapEvents(true);
		Capsule->OnComponentBeginOverlap.AddDynamic(this, &ACombatEnemy::OnCapsuleOverlap);
	}
}

void ACombatEnemy::HandleDeath()
{
	UE_LOG(LogTemp, Warning, TEXT("ACombatEnemy: %s died! Destroying actor in C++."), *GetName());
	Destroy();
}

void ACombatEnemy::OnCapsuleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this) return;

	// Check if we hit the Player Character
	if (IAshenCharacterInterface* Interface = Cast<IAshenCharacterInterface>(OtherActor))
	{
		if (UAshenOath_HealthComponent* PlayerHealth = Interface->Execute_GetHealthComponent(OtherActor))
		{
			UE_LOG(LogTemp, Warning, TEXT("ACombatEnemy: %s touched Player %s -> Dealing 40.0 damage!"), *GetName(), *OtherActor->GetName());
			PlayerHealth->ReceiveDamage(40.0f, this);
		}
	}
}
