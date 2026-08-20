// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionTrustNPCReactivityAdapter.generated.h"

/**
 * UAshenCompanionTrustNPCReactivityAdapter
 * Adapter translating companion trust states into town NPC dialogue attitudes and merchant discount modifiers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionTrustNPCReactivityAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionTrustNPCReactivityAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Core")
	float TownMerchantDiscountFactor = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	void UpdateNPCReactivityForCompanionTrust(float GarrettTrust, float SerafinaTrust);
};
