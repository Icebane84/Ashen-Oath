// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AAshenCampfireSpatialInspectionActor.generated.h"

UCLASS()
class ASHENOATH_API AAshenCampfireSpatialInspectionActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireSpatialInspectionActor();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void SelectCompanionFocus(FName CompanionID);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | World")
	FName GetCurrentCompanionFocus() const { return CurrentCompanionFocus; }

private:
	FName CurrentCompanionFocus;
};
