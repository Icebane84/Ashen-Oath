// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CombatEnemy.generated.h"

/**
 * ACombatEnemy
 *
 * Base Enemy Character class for Ashen Oath enemies.
 */
class UAshenOath_HealthComponent;

UCLASS()
class ASHENOATH_API ACombatEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	ACombatEnemy();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UAshenOath_HealthComponent* HealthComponent;

	UFUNCTION()
	virtual void HandleDeath();

	UFUNCTION()
	virtual void OnCapsuleOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
