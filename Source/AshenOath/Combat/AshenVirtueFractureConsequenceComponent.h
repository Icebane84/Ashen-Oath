// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenVirtueFractureConsequenceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVirtueFractureInflictedSignature, FName, FractureTag, float, ConfidencePenalty);

/**
 * UAshenVirtueFractureConsequenceComponent
 *
 * Component degrading Garrett's confidence and altering Kaelen's nightmare labyrinths upon Virtue Fracture imprint (Directive #2).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVirtueFractureConsequenceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenVirtueFractureConsequenceComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VirtueFracture")
	void InflictVirtueFracture(FName FractureTag, float Severity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VirtueFracture|Events")
	FOnVirtueFractureInflictedSignature OnVirtueFractureInflicted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VirtueFracture")
	FName ActiveFractureTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VirtueFracture")
	float GarrettConfidencePenalty = 0.0f;
};
