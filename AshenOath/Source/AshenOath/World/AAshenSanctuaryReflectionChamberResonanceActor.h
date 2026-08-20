// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AAshenSanctuaryReflectionChamberResonanceActor.generated.h"

/**
 * AAshenSanctuaryReflectionChamberResonanceActor
 * World actor driving Sanctuary reflection chamber ambient lighting.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryReflectionChamberResonanceActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryReflectionChamberResonanceActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	FLinearColor GetChamberAmbientColor() const { return ChamberAmbientColor; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	FLinearColor ChamberAmbientColor = FLinearColor::White;
};
