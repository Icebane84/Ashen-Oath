// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionPostureSynergyDirector.generated.h"

/**
 * UAshenCompanionPostureSynergyDirector
 * AI Director component orchestrating 3-character posture stance synergy positioning.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionPostureSynergyDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionPostureSynergyDirector();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	bool bPostureSynergyActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool SynchronizePostureSynergyFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina);
};
