// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenIllusoryDoorwayActor.generated.h"

/**
 * AAshenIllusoryDoorwayActor
 * World actor appearing as a solid wall or open doorway depending on Kaelen's perception.
 */
UCLASS()
class ASHENOATH_API AAshenIllusoryDoorwayActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenIllusoryDoorwayActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bIsDoorwayIllusionActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void SetIllusoryState(bool bActive);
};
