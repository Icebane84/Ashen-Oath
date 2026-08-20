// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenAscensionChamberVolume.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAscensionChamberActivatedSignature, AActor*, InitiatorActor, FName, AscensionTierTag);

/**
 * AAshenAscensionChamberVolume
 *
 * Trigger volume orchestrating sanctuary ascension, heartstone resonance, and camera transitions.
 */
UCLASS()
class ASHENOATH_API AAshenAscensionChamberVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenAscensionChamberVolume();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Ascension")
	void TriggerAscensionRitual(AActor* InitiatorActor, FName AscensionTierTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Ascension|Events")
	FOnAscensionChamberActivatedSignature OnAscensionActivated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Ascension")
	bool bAscensionActive = false;
};
