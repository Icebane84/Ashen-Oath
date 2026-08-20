// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenSanctuaryHeartstoneLuminescenceModulatorActor.generated.h"

/**
 * AAshenSanctuaryHeartstoneLuminescenceModulatorActor
 * World actor driving campfire flame glow and hearth embers based on FSoulStateVector.
 */
UCLASS()
class ASHENOATH_API AAshenSanctuaryHeartstoneLuminescenceModulatorActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSanctuaryHeartstoneLuminescenceModulatorActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void ModulateHearthLuminescence(const FSoulStateVector& Vector);
};
