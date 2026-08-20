// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSanctuaryCrucibleFlameResonanceActor.generated.h"

/**
 * AAshenSanctuaryCrucibleFlameResonanceActor
 * World actor driving Sanctuary campfire intensity during SLM compilation.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryCrucibleFlameResonanceActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryCrucibleFlameResonanceActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetCrucibleFlameGlowScalar() const { return CrucibleFlameGlowScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float CrucibleFlameGlowScalar = 1.0f;
};
