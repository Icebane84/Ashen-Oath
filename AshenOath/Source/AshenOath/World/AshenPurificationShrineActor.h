// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenPurificationShrineActor.generated.h"

/**
 * AAshenPurificationShrineActor
 * Interactive sanctuary world actor offering somatic corruption cleansing and health recovery.
 */
UCLASS()
class ASHENOATH_API AAshenPurificationShrineActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenPurificationShrineActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	float CleansingRadius = 400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	bool bShrineConsecrated = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sanctuary")
	bool PerformPurificationRitual(AActor* InstigatorActor);
};
