// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFlashPowderComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFlashBlindnessStateChangedSignature, bool, bIsBlinded);

/**
 * UAshenFlashPowderComponent
 *
 * Attached to enemy pawns hit by Garrett's flash powder bombs.
 * Applies temporary blindness (dazing enemy AI, applying 50% movement speed penalty).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFlashPowderComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFlashPowderComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Alchemical")
	void ApplyFlashBlindness(float Duration = 4.0f);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Alchemical")
	void ClearFlashBlindness();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Alchemical")
	bool bIsBlinded = false;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Alchemical|Events")
	FOnFlashBlindnessStateChangedSignature OnBlindnessStateChanged;

private:
	FTimerHandle BlindnessTimerHandle;
};
