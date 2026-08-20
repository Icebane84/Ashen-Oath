// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSomaticIdentityTouchstoneActor.generated.h"

/**
 * AAshenSomaticIdentityTouchstoneActor
 * Interactive world touchstone actor stabilizing local somatic identity echoes and psychological resonance fields.
 */
UCLASS()
class ASHENOATH_API AAshenSomaticIdentityTouchstoneActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSomaticIdentityTouchstoneActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Touchstone")
	float StabilizationRadius = 800.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Touchstone")
	bool bTouchstoneActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Touchstone")
	bool ActivateIdentityTouchstone();
};
