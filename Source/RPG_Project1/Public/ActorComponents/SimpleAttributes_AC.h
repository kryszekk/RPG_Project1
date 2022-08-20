// All rights reserved

#pragma once

#include "Interfaces/SimpleAttributes_AC_I.h"
#include "Structures/SimpleAttributes_F.h"

#include "CoreMinimal.h"
#include "AttributesBase_AC.h"
#include "SimpleAttributes_AC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_PROJECT1_API USimpleAttributes_AC : public UAttributesBase_AC, public ISimpleAttributes_AC_I
{
	GENERATED_BODY()
	
public:	
	USimpleAttributes_AC();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	virtual void TryGetHitByEnemy_Implementation(const float& IncomingPhysicalDamage, const float& IncomingMagicalDamage) override;
	
	/** All combat attributes that this unit has */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FSimpleAttributes_F SAttributes;

protected:
	virtual void BeginPlay() override;

	
	/** Sets the values of attributes based on:
	* level,
	* attribute multiplier,
	* game difficulty multiplier
	**/
	UFUNCTION()
	void ProcedurallySetAttributes();
	
private:
	UFUNCTION()
	void InflictDamage(const float& IncPhysicalDamage, const float& IncMagicalDamage);
};
