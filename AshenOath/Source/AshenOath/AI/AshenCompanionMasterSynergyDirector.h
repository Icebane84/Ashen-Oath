// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionMasterSynergyDirector.generated.h"

/**
 * UAshenCompanionMasterSynergyDirector
 * AI Director component orchestrating 3-character companion master synergy tactical formation positioning.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionMasterSynergyDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionMasterSynergyDirector();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	bool bMasterSynergyActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool SynchronizeMasterSynergyFormation(AActor* LeaderActor, AActor* CompanionGarrett, AActor* CompanionSerafina);
};
