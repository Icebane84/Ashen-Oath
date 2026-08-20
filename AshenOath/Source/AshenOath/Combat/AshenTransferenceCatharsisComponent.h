// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenWhiteFlameTypes.h"
#include "AshenTransferenceCatharsisComponent.generated.h"

/**
 * UAshenTransferenceCatharsisComponent
 * Manages the exothermic transmutation of oily black Nyxian sap in Serafina's veins into White Pyre-Aether, reducing burnout by 50%.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTransferenceCatharsisComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTransferenceCatharsisComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float PyreAetherPurity = 0.0f; // 0.0 to 1.0

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float BurnoutReliefScalar = 0.50f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	bool TransmuteSapToAether(float CurrentBurnout, float& OutNewBurnout);
};
