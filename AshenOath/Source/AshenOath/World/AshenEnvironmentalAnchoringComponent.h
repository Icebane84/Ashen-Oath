// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnvironmentalAnchoringComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAnchorStateChangedSignature, bool, bIsAnchored, float, CorruptionReductionFactor);

/**
 * UAshenEnvironmentalAnchoringComponent
 *
 * Interactive world anchor component allowing player to bind Light/Shadow anchors to stabilize localized environmental corruption.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEnvironmentalAnchoringComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEnvironmentalAnchoringComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Anchoring")
	bool BindEnvironmentalAnchor();

	UFUNCTION(BlueprintPure, Category = "AshenOath|Anchoring")
	bool IsAnchored() const { return bIsAnchored; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Anchoring|Events")
	FOnAnchorStateChangedSignature OnAnchorStateChanged;

private:
	bool bIsAnchored = false;
};
