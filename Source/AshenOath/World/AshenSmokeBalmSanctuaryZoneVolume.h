// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenSmokeBalmSanctuaryZoneVolume.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSmokeBalmZoneEnteredSignature, AActor*, EnteringActor, float, ConcealmentLevel);

/**
 * AAshenSmokeBalmSanctuaryZoneVolume
 *
 * World Volume providing stealth concealment and stamina regen inside Garrett's smoke balm cloud (PRS-001 Garrett Slice).
 */
UCLASS()
class ASHENOATH_API AAshenSmokeBalmSanctuaryZoneVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenSmokeBalmSanctuaryZoneVolume();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SmokeZone")
	void ApplyConcealmentToActor(AActor* TargetActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SmokeZone|Events")
	FOnSmokeBalmZoneEnteredSignature OnZoneEntered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SmokeZone")
	float ActiveConcealmentRating = 90.0f;
};
