// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRelationalPincerFormationDirector.generated.h"

/**
 * UAshenRelationalPincerFormationDirector
 * AI Director component coordinating companion pincer tactical formation positioning around high-priority targets.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRelationalPincerFormationDirector : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRelationalPincerFormationDirector();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	bool bPincerFormationActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool CoordinatePincerFormation(AActor* TargetLeader, AActor* CompanionGarrett, AActor* CompanionSerafina);
};
