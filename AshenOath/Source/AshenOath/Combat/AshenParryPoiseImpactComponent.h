// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenParryPoiseImpactComponent.generated.h"

/**
 * UAshenParryPoiseImpactComponent
 * Deals massive posture damage (80.0) to attackers on successful parry, breaking poise.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParryPoiseImpactComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenParryPoiseImpactComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float BasePostureDamage = 80.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float CalculatePostureDamageDealt(float PoiseMultiplier = 1.0f) const;
};
