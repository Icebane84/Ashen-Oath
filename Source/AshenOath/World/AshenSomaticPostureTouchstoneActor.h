// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSomaticPostureTouchstoneActor.generated.h"

/**
 * AAshenSomaticPostureTouchstoneActor
 * Interactive world touchstone actor stabilizing local somatic posture stance alignment fields.
 */
UCLASS()
class ASHENOATH_API AAshenSomaticPostureTouchstoneActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenSomaticPostureTouchstoneActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Touchstone")
	float PostureStabilizationRadius = 850.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Touchstone")
	bool bPostureTouchstoneActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Touchstone")
	bool ActivatePostureTouchstone();
};
