// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenCombatTrainingDummyActor.generated.h"

/**
 * AAshenCombatTrainingDummyActor
 * Interactive combat training dummy measuring DPS, stagger accumulation, and flank execution angle accuracy.
 */
UCLASS()
class ASHENOATH_API AAshenCombatTrainingDummyActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenCombatTrainingDummyActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float TotalDamageReceived = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	int32 FlankHitsCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void RecordCombatHit(float Damage, bool bWasFlank);
};
