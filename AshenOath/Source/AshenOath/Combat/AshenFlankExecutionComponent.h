// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFlankExecutionComponent.generated.h"

/**
 * UAshenFlankExecutionComponent
 * Evaluates rear attack alignment angle (<45 degrees), calculates 2.0x flank execution damage multiplier, and computes motion warp vectors.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFlankExecutionComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFlankExecutionComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float MaxFlankAngleDegrees = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float FlankDamageMultiplier = 2.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool IsFlankingEnemy(const FVector& AttackerLocation, const FVector& EnemyLocation, const FVector& EnemyForwardVector, float& OutAngleDegrees) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float CalculateFlankDamage(float BaseDamage, bool bIsFlanking) const;
};
