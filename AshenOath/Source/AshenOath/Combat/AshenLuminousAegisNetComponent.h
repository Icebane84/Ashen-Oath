// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenLuminousAegisNetComponent.generated.h"

/**
 * UAshenLuminousAegisNetComponent
 * Component calculating reactive golden thread net deployment, absorbing 75% of incoming poise damage and tracking thread rupture thresholds.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLuminousAegisNetComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLuminousAegisNetComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	bool bIsNetActive = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float PoiseAbsorptionPercentage = 0.75f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	int32 RemainingPoiseBreakShields = 2;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	bool AbsorbPoiseStrike(float IncomingPoiseDamage, float& OutAbsorbedPoise, bool& bDidThreadSnap);
};
