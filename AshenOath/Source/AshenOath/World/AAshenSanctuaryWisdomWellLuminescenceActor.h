// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AAshenSanctuaryWisdomWellLuminescenceActor.generated.h"

/**
 * AAshenSanctuaryWisdomWellLuminescenceActor
 * World actor driving liquid luminescence in Sanctuary Well of Wisdom.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryWisdomWellLuminescenceActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryWisdomWellLuminescenceActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetWellLuminescenceIntensity() const { return WellLuminescenceIntensity; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float WellLuminescenceIntensity = 1.0f;
};
