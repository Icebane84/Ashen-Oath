// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenConstellationRespecComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConstellationRespecExecutedSignature, FName, RefundedPerkID, int32, RefundedImprintCount);

/**
 * UAshenConstellationRespecComponent
 *
 * Enables Kaelen to respec identity perk nodes at sanctuary campfires,
 * removing active perks and refunding allocated imprints directly back into UAshenOath_ImprintBufferComponent.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenConstellationRespecComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenConstellationRespecComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Constellation")
	bool RefundPerkNode(FName PerkID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Constellation")
	int32 ResetAllConstellationPerks();

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Constellation|Events")
	FOnConstellationRespecExecutedSignature OnRespecExecuted;
};
